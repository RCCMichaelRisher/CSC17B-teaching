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

    // Method to handle firing at a guessed location
    fire(guess) {
        for (let i = 0; i < this.numShips; i++) {
            const ship = this.ships[i];
            const index = ship.locations.indexOf(guess);

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

    // Method to check if a ship is completely sunk
    isSunk(ship) {
        for (let i = 0; i < ship.shipLength; i++) { // Use the ship's specific length
            if (ship.hits[i] !== "hit") {
                return false; // If any part of the ship is not hit, it's not sunk
            }
        }
        return true; // All parts of the ship are hit
    }

    // Generate random locations for all ships
    generateShipLocations() {
        let locations;
        for (let i = 0; i < this.numShips; i++) {
            const ship = this.ships[i]; // Get the current ship
            do {
                locations = this.generateShip(ship.shipLength); // Generate a new ship with its specific length
            } while (this.collision(locations)); // Ensure no collisions with existing ships
            ship.locations = locations; // Assign the generated locations to the ship
        }
        console.log("Ships array: ");
        console.log(this.ships); // Log the ship locations for debugging
    }

    // Generate a single ship's locations
    generateShip(shipLength) {
        const direction = Math.floor(Math.random() * 2); // Randomly choose horizontal or vertical
        let row, col;

        if (direction === 1) { // Horizontal
            row = Math.floor(Math.random() * this.boardSize);
            col = Math.floor(Math.random() * (this.boardSize - shipLength + 1));
        } else { // Vertical
            row = Math.floor(Math.random() * (this.boardSize - shipLength + 1));
            col = Math.floor(Math.random() * this.boardSize);
        }

        const newShipLocations = [];
        for (let i = 0; i < shipLength; i++) {
            if (direction === 1) {
                newShipLocations.push(row + "" + (col + i)); // Add horizontal locations
            } else {
                newShipLocations.push((row + i) + "" + col); // Add vertical locations
            }
        }
        return newShipLocations;
    }

    // Check if a new ship's locations collide with existing ships
    collision(locations) {
        for (let i = 0; i < this.numShips; i++) {
            const ship = this.ships[i];
            for (let j = 0; j < locations.length; j++) {
                if (ship.locations.indexOf(locations[j]) >= 0) {
                    return true; // Collision detected
                }
            }
        }
        return false; // No collision
    }
}

const model = new Model(); // Create an instance of the Model class