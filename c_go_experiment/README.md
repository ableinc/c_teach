
# cgo Experiment: Advanced Guide

This project is a practical reference for integrating C code with Go using cgo. It demonstrates how to build, link, and call C code from Go, and how to use cgo directives for real-world scenarios.

## Key cgo Directives (in Go source)

```go
/*
#cgo CFLAGS:   -I .
#cgo LDFLAGS:  -L . -lcalc
#include "calculator.h"
*/
import "C"
```

- `#cgo CFLAGS:`   — Passes flags to the C compiler (e.g., `-I .` to include current dir for headers).
- `#cgo LDFLAGS:`  — Passes flags to the linker (e.g., `-L .` to search current dir, `-lcalc` to link libcalc).
- `#include`        — Includes C headers for use in Go.
- `//export Foo`    — Exposes a Go function to C (must be before the function).

### Other Useful Directives
- `#cgo CPPFLAGS:`      — Passes flags to the C preprocessor.
- `#cgo pkg-config:`    — Uses pkg-config for flags (e.g., `#cgo pkg-config: libssl`).
- Platform-specific:    `#cgo windows LDFLAGS: ...` (see cgo docs for syntax).

## Build & Run

1. Build the C shared library:
	```sh
	./build-shared-library.sh
	```
2. Build and run Go code:
	```sh
	go run main.go
	# or
	go build -o calc_app main.go && ./calc_app
	```

## Learning cgo

- Place cgo directives in a comment block immediately before `import "C"`.
- Use Go types for C types via `C.TypeName` (e.g., `C.int`).
- You can call C functions as `C.funcname()`.
- For more, see: https://pkg.go.dev/cmd/cgo

---
This repo is a minimal, practical cgo reference. Edit, break, and experiment to learn more.
