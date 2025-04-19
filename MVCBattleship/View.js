class View {
    // Method to display a message to the player
    displayMessage(msg) {
        const messageArea = document.getElementById("messageArea"); // Get the message area element
        messageArea.innerHTML = msg; // Update the message area with the provided message
    }

    // Method to visually mark a hit on the board
    displayHit(location) {
        const cell = document.getElementById(location); // Get the cell element by its ID
        cell.setAttribute("class", "hit"); // Set the cell's class to "hit" for styling
    }

    // Method to visually mark a miss on the board
    displayMiss(location) {
        const cell = document.getElementById(location); // Get the cell element by its ID
        cell.setAttribute("class", "miss"); // Set the cell's class to "miss" for styling
    }
}

const view = new View(); // Create an instance of the View class