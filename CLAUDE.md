# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

This is a C++ library providing timer management functionality through the `aTimerController` class. The library is designed for embedded systems or applications requiring precise timing control with support for up to 255 concurrent timers.

## Architecture

### Core Components

- **aTimerController Class** (`src/aTimerController.h`, `src/aTimerController.cpp`)
  - Manages multiple timers (up to 255) with millisecond precision
  - Tracks elapsed time for each timer against configurable wait durations
  - Uses array-based storage for timer states and wait durations
  - Maintains an active timer index for coordinated time updates

### Key Design Patterns

- **Index-based Timer Management**: Timers are accessed via unsigned char indices (0-254)
- **Active Timer Pattern**: One timer serves as the "current time" reference for all other timers
- **Bounds Checking**: All timer operations validate index ranges before accessing arrays

## Development Commands

This project uses a minimal C++ structure without build system files. Development requires manual compilation:

### Building
```bash
# Compile the library
g++ -c src/aTimerController.cpp -o aTimerController.o

# Create static library
ar rcs libaTimerController.a aTimerController.o

# Compile with application code
g++ -std=c++11 your_main.cpp src/aTimerController.cpp -o your_program
```

### Testing
No formal test framework is configured. Create test files manually and compile them with the library.

## Language and Documentation

- **Primary Language**: Japanese (comments and documentation)
- **Code Style**: Standard C++ with Doxygen-style documentation
- **Naming Convention**: camelCase for methods, lowercase with underscores for private members

## Timer Usage Patterns

The timer system works on a reference-based model:
1. Set wait durations for specific timer indices
2. Update the active timer with current system time
3. Reset individual timers to start their countdown
4. Check elapsed status against wait durations

The active timer (default index 0) serves as the master clock reference for all timer calculations.