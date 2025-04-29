
/* global controller, model */

// event handlers

function handleFireButton() {
    let guessInput = document.getElementById("guessInput");
    let guess = guessInput.value.toUpperCase();

    controller.processGuess(guess);

    guessInput.value = "";
}

function handleKeyPress(e) {
    let fireButton = document.getElementById("fireButton");

    if (e.keyCode === 13) {
            fireButton.click();
            return false;
    }
}

// init - called when the page has completed loading

window.onload = init;

function init() {
    // Fire! button onclick handler
    let fireButton = document.getElementById("fireButton");
    fireButton.onclick = handleFireButton;

    // handle "return" key press
    let guessInput = document.getElementById("guessInput");
    guessInput.onkeydown = handleKeyPress;

    // place the ships on the game board
    model.generateShipLocations();
}