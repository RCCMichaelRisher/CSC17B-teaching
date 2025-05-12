/*
 * Author:      Dr. Mark E. Lehr

 * Purpose:     Question class
 */

class Question {
    constructor(category, question, answers) {
        // How many arguments are provided
        const nArgs = arguments.length; // The number of arguments passed to the function
        if (nArgs === 0 || nArgs > 3) { // Empty Question
            this.cat = "";
            this.quest = "";
        } else if (nArgs === 3) { // Question provided with all inputs
            this.cat = category;
            this.quest = question;
            this.ans = answers;
        } else if (nArgs === 2) { // Question provided with no answers added later
            this.cat = category;
            this.quest = question;
        } else {
            this.cat = category.cat;
            this.quest = category.qstn;
            this.ans = category.ans;
        }
    }

    // Setting the Category
    setCat(category) {
        this.cat = category;
    }

    // Setting the Question
    setQstn(question) {
        this.quest = question;
    }

    // Adding an Answer
    addAns(answer) {
        this.ans.push(answer);
    }

    // Accessing the Category
    getCat() {
        return this.cat;
    }

    // Accessing the Question
    getQstn() {
        return this.quest;
    }

    // Accessing one of the Answers
    getAns(number) {
        if (number >= 0 && number < this.ans.length) {
            return this.ans[number];
        } else {
            return "This is not a Question";
        }
    }

    // Displaying the Question
    display( parent ) {
        let p = document.createElement( "p" );
        p.textContent = this.quest;
        // document.write("<p>" + this.quest + "</p>");
        parent.appendChild( p );
        for (let i = 0; i < this.ans.length; i++) {
            if (this.ans[i].length > 0) {
                let label = document.createElement( "label");
                label.textContent = this.ans[i];
                let input = document.createElement( "input" );
                Object.assign( input, {
                    type: 'radio',
                    name: this.cat,
                    value: this.ans[i]
                });
                label.appendChild( input );
                parent.appendChild( label );
                // document.write('<input type="radio" name=' + this.cat + " value=" + this.ans +
                    // ">" + this.ans[i] + "<br> </br>");
            }
        }
    }
}