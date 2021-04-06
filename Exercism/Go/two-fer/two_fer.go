// package twofer
package twofer

import "fmt"

// ShareWith (Function): Returns a string of the form "One for $you, one for me."
func ShareWith(name string) string {
	// Testcase requires that if input string is empty, we place "you" as the default
	if name == "" {
		name = "you"
	}
	return fmt.Sprintf("One for %s, one for me.", name)
}
