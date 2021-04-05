# Hello World

The classical introductory exercise. Just say "Hello, World!".

["Hello, World!"](http://en.wikipedia.org/wiki/%22Hello,_world!%22_program) is
the traditional first program for beginning programming in a new language
or environment.

The objectives are simple:

- Write a function that returns the string "Hello, World!".
- Run the test suite and make sure that it succeeds.
- Submit your solution and check it at the website.

If everything goes well, you will be ready to fetch your first real exercise.

## Coding the solution

Look for a stub file having the name hello_world.go
and place your solution code in that file.

## Running the tests

To run the tests run the command `go test` from within the exercise directory.

If the test suite contains benchmarks, you can run these with the `--bench` and `--benchmem`
flags:

    go test -v --bench . --benchmem

Keep in mind that each reviewer will run benchmarks on a different machine, with
different specs, so the results from these benchmark tests may vary.

## Further information

For more detailed information about the Go track, including how to get help if
you're having trouble, please visit the exercism.io [Go language page](http://exercism.io/languages/go/resources).

## Source

This is an exercise to introduce users to using Exercism [http://en.wikipedia.org/wiki/%22Hello,_world!%22_program](http://en.wikipedia.org/wiki/%22Hello,_world!%22_program)

## Submitting Incomplete Solutions
It's possible to submit an incomplete solution so you can see how others have completed the exercise.

## Solution
```
// Greeting the world, the programmer way!
// https://golang.org/doc/effective_go.html#commentary
package greeting

// function that prints "Hello, World!" on the console
func HelloWorld() string {
	return "Hello, World!"
}
```
## Tests

```
package greeting

import "testing"

// Define a function named HelloWorld that takes no arguments,
// and returns a string.
// In other words, define a function with the following signature:
// HelloWorld() string

func TestHelloWorld(t *testing.T) {
	expected := "Hello, World!"
	if observed := HelloWorld(); observed != expected {
		t.Fatalf("HelloWorld() = %v, want %v", observed, expected)
	}
}

// BenchmarkHelloWorld() is a benchmarking function. These functions follow the
// form `func BenchmarkXxx(*testing.B)` and can be used to test the performance
// of your implementation. They may not be present in every exercise, but when
// they are you can run them by including the `-bench` flag with the `go test`
// command, like so: `go test -v --bench . --benchmem`
//
// You will see output similar to the following:
//
// BenchmarkHelloWorld   	2000000000	         0.46 ns/op
//
// This means that the loop ran 2000000000 times at a speed of 0.46 ns per loop.
//
// While benchmarking can be useful to compare different iterations of the same
// exercise, keep in mind that others will run the same benchmarks on different
// machines, with different specs, so the results from these benchmark tests may
// vary.
func BenchmarkHelloWorld(b *testing.B) {
	for i := 0; i < b.N; i++ {
		HelloWorld()
	}
}
```