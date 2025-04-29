class View {
    /**
     * Displays a message to the player in the message area.
     * @param {string} msg - The message to display.
     */
    displayMessage(msg) {
        let messageArea = document.getElementById("messageArea"); // Get the message area element
        messageArea.innerHTML = msg; // Update the message area with the provided message
    }

    /**
     * Visually marks a hit on the game board.
     * @param {string} location - The ID of the cell to mark as a hit.
     */
    displayHit(location) {
        let cell = document.getElementById(location); // Get the cell element by its ID
        cell.setAttribute("class", "hit"); // Set the cell's class to "hit" for styling
    }

    /**
     * Visually marks a miss on the game board.
     * @param {string} location - The ID of the cell to mark as a miss.
     */
    displayMiss(location) {
        let cell = document.getElementById(location); // Get the cell element by its ID
        cell.setAttribute("class", "miss"); // Set the cell's class to "miss" for styling
    }
}

let view = new View(); // Create an instance of the View class