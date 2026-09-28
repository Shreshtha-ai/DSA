# 📚 Infix / Prefix / Postfix — Exam Revision Notes

---

## 🔑 Notation Quick Reference

| Notation    | Operator Position | Example        |
|-------------|-------------------|----------------|
| **Infix**   | Between operands  | `A + B`        |
| **Prefix**  | Before operands   | `+ A B`        |
| **Postfix** | After operands    | `A B +`        |

> **Key insight:** Prefix & Postfix never need parentheses — precedence is implicit in the order.

---

## ⚖️ Operator Precedence (used in Infix conversions)

| Operator | Priority |
|----------|----------|
| `^`      | 3 (highest) |
| `*` `/`  | 2 |
| `+` `-`  | 1 (lowest) |
| `(`      | 0 |

---

## 🗺️ Conversion Map (All 6 Transformations)

```
              INFIX  (A + B * C)
             /                  \
   InfixToPostfix            InfixToPrefix
           /                          \
      POSTFIX (ABC*+)  <-->  PREFIX (+A*BC)
           \                          /
    PostfixToInfix            PrefixToInfix
             \                  /
              INFIX  (back again)
```

---

## 1️⃣  Infix → Postfix

**File:** InfixToPostfix.cpp

### Algorithm
```
Use a stack<char> for operators, string for result.
Scan LEFT → RIGHT:

  if operand  → append to result
  if '('      → push to stack
  if ')'      → pop & append until '(' found, then discard '('
  if operator → while stack not empty AND priority(current) <= priority(stack.top()):
                     pop & append
                 push current operator
After scan → pop & append all remaining stack elements
```

### Pseudocode
```
function infixToPostfix(s):
    stack st
    result = ""
    for each char c in s (left to right):
        if isOperand(c):
            result += c
        elif c == '(':
            st.push(c)
        elif c == ')':
            while st.top() != '(':
                result += st.top(); st.pop()
            st.pop()          // discard '('
        else:                 // operator
            while not empty AND priority(c) <= priority(st.top()):
                result += st.top(); st.pop()
            st.push(c)
    while not st.empty():
        result += st.top(); st.pop()
    return result
```

### 💡 Key Points
- `<=` in the while condition → left-associative (same priority pops first)
- `(` is pushed directly, never triggers popping by operators
- `(` has priority 0, so nothing pops it

### Example
```
Input:  a+b*c
  a → result="a"
  + → push        | stack=[+]
  b → result="ab"
  * → priority(*)>priority(+) → push | stack=[+,*]
  c → result="abc"
  end: pop * → "abc*", pop + → "abc*+"
Output: abc*+
```

---

## 2️⃣  Infix → Prefix

**File:** InfixToPrefix.cpp

### Algorithm
```
TRICK — reuse Infix→Postfix with 3 extra steps:
  Step 1: Reverse the infix string
  Step 2: Swap all '(' ↔ ')' in the reversed string
  Step 3: Run the postfix algorithm BUT with modified operator condition:
            - for '^':  use <=  (right-assoc stays right-assoc after reversal)
            - for others: use strict <  (KEY DIFFERENCE from InfixToPostfix)
  Step 4: Reverse the result string
```

### Pseudocode
```
function infixToPrefix(s):
    reverse(s)
    for each char: swap '(' <-> ')'
    // modified postfix:
    stack st, result = ""
    for each char c in s:
        if isOperand(c): result += c
        elif c == '(': st.push(c)
        elif c == ')':
            while st.top() != '(': result += st.top(); st.pop()
            st.pop()
        else:
            if c == '^':
                while priority(c) <= priority(st.top()): pop & append
            else:
                while priority(c) < priority(st.top()): pop & append  // ← strict <
            st.push(c)
    drain stack into result
    reverse(result)
    return result
```

### 💡 Key Points
- **Mnemonic: R-S-P-R** → Reverse, Swap brackets, run Postfix, Reverse result
- Condition changes to **strict `<`** for `+`, `-`, `*`, `/` (not `^`)
- This handles right-to-left associativity correctly after the reversal

### Example
```
Input:    a+b*c
Step 1:   c*b+a
Step 2:   c*b+a  (no brackets to swap)
Step 3 postfix: cb*a+
Step 4 reverse: +a*bc
Output:   +a*bc
```

---

## 3️⃣  Postfix → Infix

**File:** PostfixToInfix.cpp

### Algorithm
```
Use a stack<string>.
Scan LEFT → RIGHT:

  if operand  → push as single-char string
  if operator → pop t1 (top first), pop t2 (second)
                form: "(" + t2 + op + t1 + ")"
                push result back
Return stack.top()
```

### Pseudocode
```
function postfixToInfix(s):
    stack<string> st
    for each char c in s (left to right):
        if isOperand(c):
            st.push(str(c))
        else:
            t1 = st.top(); st.pop()    // right operand
            t2 = st.top(); st.pop()    // left operand
            st.push("(" + t2 + c + t1 + ")")
    return st.top()
```

### 💡 Key Points
- t1 = first popped = **right** operand
- t2 = second popped = **left** operand
- Formula: `( LEFT  op  RIGHT )` = `( t2  op  t1 )`
- Stack holds **strings**, not chars

### Example
```
Input: ab+c*
  a → ["a"]
  b → ["a","b"]
  + → t1="b", t2="a" → push "(a+b)"
  c → ["(a+b)","c"]
  * → t1="c", t2="(a+b)" → push "((a+b)*c)"
Output: ((a+b)*c)
```

---

## 4️⃣  Postfix → Prefix

**File:** PostfixToprefix.cpp

### Algorithm
```
Use a stack<string>.
Scan LEFT → RIGHT:

  if operand  → push as single-char string
  if operator → pop t1 (top), pop t2 (second)
                form: op + t2 + t1
                push result back
Return stack.top()
```

### Pseudocode
```
function postfixToPrefix(s):
    stack<string> st
    for each char c in s (left to right):
        if isOperand(c):
            st.push(str(c))
        else:
            t1 = st.top(); st.pop()    // right operand
            t2 = st.top(); st.pop()    // left operand
            st.push(str(c) + t2 + t1)
    return st.top()
```

### 💡 Key Points
- Same as Postfix→Infix, only **merge formula changes**
- Formula: `op + LEFT + RIGHT` = `op + t2 + t1`
- No parentheses needed!

### Example
```
Input: ab+c*
  a → ["a"]
  b → ["a","b"]
  + → t1="b", t2="a" → push "+ab"
  c → ["+ab","c"]
  * → t1="c", t2="+ab" → push "*+abc"
Output: *+abc
```

---

## 5️⃣  Prefix → Infix

**File:** prefixToinfix.cpp

### Algorithm
```
Use a stack<string>.
Scan RIGHT → LEFT (reverse direction — KEY difference from postfix conversions):

  if operand  → push as single-char string
  if operator → pop t1 (top), pop t2 (second)
                form: "(" + t1 + op + t2 + ")"
                push result back
Return stack.top()
```

### Pseudocode
```
function prefixToInfix(s):
    stack<string> st
    i = s.size() - 1
    while i >= 0:
        if isOperand(s[i]):
            st.push(str(s[i]))
        else:
            t1 = st.top(); st.pop()
            t2 = st.top(); st.pop()
            st.push("(" + t1 + s[i] + t2 + ")")
        i--
    return st.top()
```

### 💡 Key Points
- Scan **Right → Left** (opposite of postfix conversions)
- Formula: `( t1  op  t2 )` ← note t1 comes FIRST (opposite of Postfix→Infix!)
- Compare: Postfix→Infix uses `(t2 op t1)`, Prefix→Infix uses `(t1 op t2)`

### Example
```
Input: +a*bc   (scan R→L: c, b, *, a, +)
  c → ["c"]
  b → ["c","b"]
  * → t1="b", t2="c" → push "(b*c)"
  a → ["(b*c)","a"]
  + → t1="a", t2="(b*c)" → push "(a+(b*c))"
Output: (a+(b*c))
```

---

## 6️⃣  Prefix → Postfix

**File:** prefixtopostfix.cpp

### Algorithm
```
Use a stack<string>.
Scan RIGHT → LEFT:

  if operand  → push as single-char string
  if operator → pop t1 (top), pop t2 (second)
                form: t1 + t2 + op
                push result back
Return stack.top()
```

### Pseudocode
```
function prefixToPostfix(s):
    stack<string> st
    i = s.size() - 1
    while i >= 0:
        if isOperand(s[i]):
            st.push(str(s[i]))
        else:
            t1 = st.top(); st.pop()
            t2 = st.top(); st.pop()
            st.push(t1 + t2 + str(s[i]))
        i--
    return st.top()
```

### 💡 Key Points
- Scan **Right → Left** (same as Prefix→Infix)
- Formula: `t1 + t2 + op` — operator goes to the END (postfix!)
- No parentheses needed

### Example
```
Input: /-ab*+def
Output: ab-de+f*/   ✓ (verified from your program output)
```

---

## 📊 Master Comparison Table

| Conversion       | Scan Dir | Stack Type  | Pop Order         | Merge Formula      |
|------------------|----------|-------------|-------------------|--------------------|
| Infix→Postfix    | L → R    | `char`      | priority-based    | operator handling  |
| Infix→Prefix     | L → R    | `char`      | priority-based    | R-S-P-R trick      |
| Postfix→Infix    | **L→R**  | `string`    | t1=top, t2=next   | `(t2 op t1)`       |
| Postfix→Prefix   | **L→R**  | `string`    | t1=top, t2=next   | `op + t2 + t1`     |
| Prefix→Infix     | **R→L**  | `string`    | t1=top, t2=next   | `(t1 op t2)`       |
| Prefix→Postfix   | **R→L**  | `string`    | t1=top, t2=next   | `t1 + t2 + op`     |

---

## 🧠 Memory Tricks

### 1. Scan Direction
```
Source is POSTFIX → scan LEFT to RIGHT   (postfix reads naturally L→R)
Source is PREFIX  → scan RIGHT to LEFT   (prefix op comes first, so reverse)
```

### 2. Merge Formula — "Where does the operator go?"
```
Target = Infix   → operator BETWEEN operands  → (left op right)
Target = Prefix  → operator BEFORE operands   → op + left + right
Target = Postfix → operator AFTER operands    → left + right + op
```

### 3. Left vs Right in formula (when t1=top, t2=second)
```
Postfix source (L→R scan): t1 = RIGHT operand, t2 = LEFT operand
Prefix source  (R→L scan): t1 = LEFT operand,  t2 = RIGHT operand

So:
  Postfix→Infix:   (t2 op t1)   = (LEFT op RIGHT)  ✓
  Prefix→Infix:    (t1 op t2)   = (LEFT op RIGHT)  ✓
  Postfix→Prefix:  op+t2+t1     = op+LEFT+RIGHT     ✓
  Prefix→Postfix:  t1+t2+op     = LEFT+RIGHT+op     ✓
```

### 4. Infix→Prefix shortcut
> **"RSPR"** — Reverse input → Swap brackets → run Postfix algo (with strict `<`) → Reverse result

---

## ⚡ Generic Stack Algorithm Skeleton

```cpp
// For Postfix/Prefix source conversions
string convert(string s) {
    stack<string> st;

    // Postfix source: i=0, step=+1, condition: i < s.size()
    // Prefix source:  i=s.size()-1, step=-1, condition: i >= 0

    while (/* condition */) {
        if (isalnum(s[i])) {
            st.push(string(1, s[i]));
        } else {
            string t1 = st.top(); st.pop();  // first pop
            string t2 = st.top(); st.pop();  // second pop
            // Choose merge formula based on target:
            // →Infix:   "(" + t2 + s[i] + t1 + ")"   [postfix src]
            // →Infix:   "(" + t1 + s[i] + t2 + ")"   [prefix src]
            // →Prefix:  s[i] + t2 + t1               [postfix src]
            // →Postfix: t1 + t2 + s[i]               [prefix src]
            st.push(/* formula */);
        }
        i += /* step */;
    }
    return st.top();
}
```

---

## 🧪 Test Cases

| Infix          | Postfix      | Prefix       |
|----------------|--------------|--------------|
| `a+b`          | `ab+`        | `+ab`        |
| `a+b*c`        | `abc*+`      | `+a*bc`      |
| `(a+b)*c`      | `ab+c*`      | `*+abc`      |

| Prefix Input   | Postfix Output |
|----------------|----------------|
| `/-ab*+def`    | `ab-de+f*/`    |

---

*Notes generated from source files in `d:\DSA\Prefix_Postfix_Infix\`*
