//Solution goes in Sources

struct SpaceAge {
	let seconds: Double
	let onMercury: Double
	let onVenus: Double
	let onEarth: Double
	let onMars: Double
	let onJupiter: Double
	let onSaturn: Double
	let onUranus: Double
	let onNeptune: Double
}

extension SpaceAge {
	init(_ seconds: Double) {
		self.seconds = seconds
		self.onMercury = seconds / 31557600 / 0.2408467
		self.onVenus = seconds / 31557600 / 0.61519726
		self.onEarth = seconds / 31557600
		self.onMars = seconds / 31557600 / 1.8808158
		self.onJupiter = seconds / 31557600 / 11.862615
		self.onSaturn = seconds / 31557600 / 29.447498
		self.onUranus = seconds / 31557600 / 84.016846
		self.onNeptune = seconds / 31557600 / 164.79132
	}
}