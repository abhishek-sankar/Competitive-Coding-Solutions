package space

type Planet string

func Age(t float64, p Planet) float64 {
	multiplier := 1.0
	switch p {
	case "Mercury":
		multiplier = 0.2408467
	case "Venus":
		multiplier = 0.61519726
	case "Earth":
		multiplier = 1 // is this needed? since default is already set to 1
	case "Mars":
		multiplier = 1.8808158
	case "Jupiter":
		multiplier = 11.862615
	case "Saturn":
		multiplier = 29.447498
	case "Uranus":
		multiplier = 84.016846
	case "Neptune":
		multiplier = 164.79132
	default:
		multiplier = 1
	}
	return (t / 31557600 / multiplier)
}

/*
Stuff I needed
Arguments in functions: https://www.geeksforgeeks.org/function-arguments-in-golang/
Implementing a custom type: https://stackoverflow.com/questions/18992930/create-a-custom-type-with-constraint-in-go
*/
