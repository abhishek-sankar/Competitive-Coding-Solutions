class GradeSchool {
	var roster: [Int: [String]] = [:]
	var sortedRoster: [Int: [String]] {
		get {
			var mySortedRoster: [Int: [String]] = [:]
			for (grade, students) in roster {
				mySortedRoster[grade] = students.sorted()
				}
			return mySortedRoster
		}
		set {
			roster = newValue
		}
	}

	func addStudent(_ name: String, grade: Int){
		if roster[grade] == nil {
			roster[grade] = [name]
		} else {
			roster[grade]?.append(name)
		}
	}

	func studentsInGrade(_ grade: Int) -> [String]{
		return roster[grade] ?? []
	}

}