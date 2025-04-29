/* global model, view */

class Controller {
    /**
     * Initializes the Controller with a guess counter.
     */
    constructor() {
        this.guesses = 0; // Counter to track the number of guesses made by the player
    }

    /**
     * Processes the player's guess, updates the game state, and checks for victory.
     * @param {string} guess - The player's guess (e.g., "A3").
     */
    processGuess(guess) {
        let location = this.parseGuess(guess); // Parse the guess into a valid board location
        if (location) {
            this.guesses++; // Increment the guess counter
            let hit = model.fire(location); // Attempt to fire at the guessed location
            if (hit && model.shipsSunk === model.numShips) {
                // If all ships are sunk, display a victory message
                view.displayMessage("You sank all my battleships, in " 
                        + this.guesses + " guesses");
            }
        }
    }

    /**
     * Parses the player's guess into a valid board location.
     * @param {string} guess - The player's guess (e.g., "A3").
     * @returns {string|null} The valid board location as a string, or null if invalid.
     */
    parseGuess(guess) {
        const alphabet = ["A", "B", "C", "D", "E", "F", "G"]; // Valid row letters

        if (guess === null || guess.length !== 2) {
            // Validate the input length
            alert("Oops, please enter a letter and a number on the board.");
        } else {
            let firstChar = guess.charAt(0); // Extract the row letter
            let row = alphabet.indexOf(firstChar); // Convert the letter to a row index
            let column = guess.charAt(1); // Extract the column number

            if (isNaN(row) || isNaN(column)) {
                // Check if the row or column is invalid
                alert("Oops, that isn't on the board.");
            } else if (row < 0 || row >= model.boardSize ||
                   column < 0 || column >= model.boardSize) {
                // Check if the guess is out of bounds
                alert("Oops, that's off the board!");
            } else {
                return row + column; // Return the valid board location as a string
            }
        }
        return null; // Return null if the guess is invalid
    }
}

let controller = new Controller(); // Create an instance of the Controller class