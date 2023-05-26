# BrainPP

BrainPP is a Brainfuck interpreter made in C++.

## How To Use

1. Put `brainpp.cpp` and `brainpp.hpp` inside your code folder:

  ![image](https://github.com/SinisterIcy/BrainPP/assets/99663083/d44a4501-4293-4501-a3d5-16a482bf92bf)
  
2. Include the `.hpp` file in your `main.cpp`:
```cpp
#include "brainpp.hpp"
```

3. Choose between the easy method and the full method

### Easy

```cpp
BrainPP::brainpp(<code>);
```
or
```cpp
BrainPP::brainpp(<file>, true);
```

### Full

```cpp
BrainPP::BrainPP bp = BrainPP::BrainPP();
bp.run(<code>, false);
```
or
```cpp
BrainPP::BrainPP bp = BrainPP::BrainPP();
bp.run(<file>, true);
```

### Example

```cpp
#include "brainpp.hpp"

int main() {
	BrainPP::BrainPP bp = BrainPP::BrainPP();
	bp.run("Fibonacci.bf", true);
	return 0;
}
```
This uses ![Fibonacci.bf](https://github.com/SinisterIcy/BrainPP/blob/main/src/Fibonacci.bf) as input
