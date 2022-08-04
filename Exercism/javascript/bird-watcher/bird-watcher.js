// @ts-check
//
// The line above enables type checking for this file. Various IDEs interpret
// the @ts-check directive. It will give you helpful autocompletion when
// implementing this exercise.

/**
 * Calculates the total bird count.
 *
 * @param {number[]} birdsPerDay
 * @returns {number} total bird count
 */
export function totalBirdCount(birdsPerDay) {
  return birdsPerDay.reduce((previousValue, currentValue) => previousValue + currentValue, 0);	
}

/**
 * Calculates the total number of birds seen in a specific week.
 *
 * @param {number[]} birdsPerDay
 * @param {number} week
 * @returns {number} birds counted in the given week
 */
 export function birdsInWeek(birdsPerDay, week) {
	return birdsPerDay.filter((birds, index) => index >= 7 * (week -1) && index < 7 * week).reduce((previousValue, currentValue) => previousValue + currentValue, 0)
  }
/**
 * Fixes the counting mistake by increasing the bird count
 * by one for every second day.
 *
 * @param {number[]} _birdsPerDay
 * @returns {number[]} corrected bird count data
 */
export function fixBirdCountLog(_birdsPerDay) {
	for (var i =0; i < _birdsPerDay.length; i++){
		if (i%2==0){
			_birdsPerDay[i] +=1
		}
	}
	return _birdsPerDay
}
