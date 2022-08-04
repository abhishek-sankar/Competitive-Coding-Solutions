/// <reference path="./global.d.ts" />
// @ts-check

/**
 * Implement the functions needed to solve the exercise here.
 * Do not forget to export them so they are available for the
 * tests. Here an example of the syntax as reminder:
 *
 * export function yourFunction(...) {
 *   ...
 * }
 */

/**
 * @param {number} remainingTime
 * @return {String} The current status of the lasagna
*/

export function cookingStatus(remainingTime) {
	if (remainingTime === 0) {
		return "Lasagna is done."
	} else if (remainingTime == null) {
		return "You forgot to set the timer."
	} else;{
		return "Not done, please wait."
	}
}

/**
 * @param {String[]} layers
 * @param {number} averagePreparationTimePerLayer
 * @return {number} total time to prepare lasagna
 */

export function preparationTime(layers, averagePreparationTimePerLayer = 2) {
	return layers.length * averagePreparationTimePerLayer
}


/**
 * @param {String[]} layers
 * @return {Quantities} the amount of noodles and sauce needed 
 */

export function quantities(layers) {
	let noodleLayerCount = layers.filter(layer => {return layer === "noodles"}).length 
	let sauceLayerCount = layers.filter(layer => {return layer === "sauce"}).length

	return {noodles: noodleLayerCount * 50, sauce: sauceLayerCount * 0.2}
}	

/**
 * @param {String[]} friendsList
 * @param {String[]} myList
 */

export function addSecretIngredient(friendsList, myList) {
	myList.push(friendsList[friendsList.length - 1])
}

/**
 * @param {{String: Number}} recipe
 * @param {number} portions
 * @return {{}} the new recipe
 */

 export function scaleRecipe(recipe, portions) {
 	let newRecipe = {}
 	for (let ingredient in recipe) {
 		newRecipe[ingredient] = recipe[ingredient] * portions / 2
 	}
 	return newRecipe
 }