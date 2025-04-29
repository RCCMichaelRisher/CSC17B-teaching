/* global view */

class Model {
    constructor() {
        // Board size and game configuration
        this.boardSize = 7; // The size of the board (7x7 grid)
        this.numShips = 4; // Number of ships in the game
        this.shipsSunk = 0; // Counter for the number of ships sunk

        // Array to store ship data (locations, hit status, and length)
        this.ships = [
            { locations: [0, 0, 0], hits: ["", "", ""], shipLength: 3 },
            { locations: [0, 0], hits: ["", ""], shipLength: 2 },
            { locations: [0, 0, 0, 0], hits: ["", "", "", ""], shipLength: 4 },
            { locations: [0, 0, 0, 0, 0], hits: ["", "", "", "", ""], shipLength: 5 }
        ];
    }

    /**
     * Handles firing at a guessed location.
     * @param {string} guess - The guessed location (e.g., "34").
     * @returns {boolean} - True if the guess hits a ship or was already hit, false otherwise.
     */
    fire(guess) {
        for (let i = 0; i < this.numShips; i++) {
            let ship = this.ships[i];
            let index = ship.locations.indexOf(guess);

            // Check if the location was already hit
            if (ship.hits[index] === "hit") {
                view.displayMessage("Oops, you already hit that location!");
                return true;
            } 
            // If the guess hits a ship
            else if (index >= 0) {
                ship.hits[index] = "hit"; // Mark the location as hit
                view.displayHit(guess); // Update the view to show a hit
                view.displayMessage("HIT!");

                // Check if the ship is completely sunk
                if (this.isSunk(ship)) {
                    view.displayMessage("You sank my battleship!");
                    this.shipsSunk++; // Increment the sunk ships counter
                }
                return true;
            }
        }
        // If the guess misses all ships
        view.displayMiss(guess); // Update the view to show a miss
        view.displayMessage("You missed.");
        return false;
    }

    /**
     * Checks if a ship is completely sunk.
     * @param {Object} ship - The ship object to check.
     * @param {string[]} ship.locations - The locations of the ship.
     * @param {string[]} ship.hits - The hit status of the ship's locations.
     * @param {number} ship.shipLength - The length of the ship.
     * @returns {boolean} - True if the ship is completely sunk, false otherwise.
     */
    isSunk(ship) {
        for (let i = 0; i < ship.shipLength; i++) { // Use the ship's specific length
            if (ship.hits[i] !== "hit") {
                return false; // If any part of the ship is not hit, it's not sunk
            }
        }
        return true; // All parts of the ship are hit
    }

    /**
     * Generates random locations for all ships and assigns them to the ships array.
     */
    generateShipLocations() {
        let locations;
        for (let i = 0; i < this.numShips; i++) {
            let ship = this.ships[i]; // Get the current ship
            do {
                locations = this.generateShip(ship.shipLength); // Generate a new ship with its specific length
            } while (this.collision(locations)); // Ensure no collisions with existing ships
            ship.locations = locations; // Assign the generated locations to the ship
        }
        console.log("Ships array: ");
        console.log(this.ships); // Log the ship locations for debugging
    }

    /**
     * Generates a single ship's locations.
     * @param {number} shipLength - The length of the ship.
     * @returns {string[]} - An array of location strings for the ship.
     */
    generateShip(shipLength) {
        let direction = Math.floor(Math.random() * 2); // Randomly choose horizontal or vertical
        let row, col;

        if (direction === 1) { // Horizontal
            row = Math.floor(Math.random() * this.boardSize); // Random row

            // Random column, ensuring the ship fits on the board
            // min = 0, max = this.boardSize - shipLength
            col = Math.floor(Math.random() * (this.boardSize - shipLength + 1)); // Ensure the ship fits on the board
        } else { // Vertical
            row = Math.floor(Math.random() * (this.boardSize - shipLength + 1)); // Ensure the ship fits on the board
            col = Math.floor(Math.random() * this.boardSize);
        }

        //add the other parts of the ship to the array
        let newShipLocations = [];
        for (let i = 0; i < shipLength; i++) {
            if (direction === 1) {
                newShipLocations.push(row + "" + (col + i)); // Add horizontal locations
            } else {
                newShipLocations.push((row + i) + "" + col); // Add vertical locations
            }
        }
        return newShipLocations;
    }

    /**
     * Checks if a new ship's locations collide with existing ships.
     * @param {string[]} locations - The locations of the new ship.
     * @returns {boolean} - True if there is a collision, false otherwise.
     */
    collision(locations) {
        for (let i = 0; i < this.numShips; i++) {
            let ship = this.ships[i];
            for (let j = 0; j < locations.length; j++) {
                if (ship.locations.indexOf(locations[j]) >= 0) {
                    return true; // Collision detected
                }
            }
        }
        return false; // No collision
    }
}

let model = new Model(); // Create an instance of the Model class