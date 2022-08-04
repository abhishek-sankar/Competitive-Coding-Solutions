// @ts-check

/**
 * Calculates the sum of the two input arrays.
 *
 * @param {number[]} array1
 * @param {number[]} array2
 * @returns {number} sum of the two arrays
 */
export function twoSum(array1, array2) {
  return getNumberFromArray(array1) + getNumberFromArray(array2)
}

/**
 * Returns a number from the array
 * @param {number[]} numberArray
 * @returns {number} value
 */

function getNumberFromArray(numberArray) {
	let value = 0
	numberArray.forEach(number => {
		value *= 10
		value += number
		})
		return value
}

/**
 * Checks whether a number is a palindrome.
 *
 * @param {number} value
 * @returns {boolean}  whether the number is a palindrome or not
 */
export function luckyNumber(value) {
	let numberAsString = String(value)
	let stringAsArrayOfChars = numberAsString.split("")
	for (let index = 0; index < stringAsArrayOfChars.length/2; index++) {
		if (stringAsArrayOfChars[index] != stringAsArrayOfChars [stringAsArrayOfChars.length - 1 - index]) {
			return false
		}
	}
	return true
}

/**
 * Determines the error message that should be shown to the user
 * for the given input value.
 *
 * @param {string|null|undefined} input
 * @returns {string} error message
 */
export function errorMessage(input) {
  if (input == null || input === ("")) {
	return "Required field"
  } else if (isNaN(+input) || +input == 0) {
	return "Must be a number besides 0"
  } else {
	return ""
  }
}
