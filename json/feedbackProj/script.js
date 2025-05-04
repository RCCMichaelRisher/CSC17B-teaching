document.getElementById("feedbackForm").addEventListener("submit", formAction); 

function formAction( e ){
  e.preventDefault(); // prevent page reload

  const clickedButton = e.target.querySelector('button[type="submit"]:focus') || e.target.querySelector('button[type="submit"]:active'); 
  const formData = new FormData( this );

  console.log( "Clicked Button:", clickedButton ); // Debugging line
  if( clickedButton.value === "JSON" ){
    toJson( formData, e );
  } else if( clickedButton.value === "XML" ){
    toXml.bind( this, e )();
  }
}

//change all classes with datatype to the selected value
function changeDatatype( value ){ 
  document.querySelectorAll(".datatype").forEach( function( element ){
    element.innerHTML = value; // change the datatype text to JSON or XML
  } );
}


function toJson( formData, e ){
  changeDatatype( "JSON" ); // change the datatype text to JSON
  const jsonObject = {};

  console.log("Form Data:", [...formData] ); // Debugging line
  console.table([...formData])

  new Response(formData).text().then(console.log) // To see the entire raw body

  formData.forEach((value, key) => {
    jsonObject[key] = value;
  });

  // Add timestamp
  jsonObject.timestamp = new Date().toISOString();

  const jsonString = JSON.stringify(jsonObject, null, 2); // pretty print
  document.getElementById("output").textContent = jsonString;


  /******************part 2 *********************/
  fetch( "saveFeedbackJson.php", {
    method: "POST",
    headers: {
      "Content-Type": "application/json"
    },
    body: JSON.stringify(jsonObject)
  } )
  .then( response => response.json() ) // convert response to JSON
  .then( result => {

    document.getElementById("output").textContent = JSON.stringify(result.message, null, 2); // pretty print
    document.getElementById("content").textContent = JSON.stringify(result.content, null, 2); // pretty print
   })
  .catch( error => {
  console.error("Error:", error); // Log any errors to the console
  document.getElementById("output").textContent = "Error: " + error.message; // Display error message in output area
  });
}


function toXml( e ){
  changeDatatype( "XML" ); // change the datatype text to XML
  const formElements = this.elements;
  const jsonObject = {};

  for (let i = 0; i < formElements.length; i++) {
    const element = formElements[i];
    if (element.name) {
      jsonObject[element.name] = element.value;
    }
  }

  // Add timestamp
  jsonObject.timestamp = new Date().toISOString();

  // Convert to XML string
  let xmlString = '<feedback>\n';
  for (const key in jsonObject) {
    xmlString += `  <${key}>${jsonObject[key]}</${key}>\n`;
  }
  xmlString += '</feedback>';

  document.getElementById("output").textContent = xmlString;


  /******************part 2 *********************/
  fetch( "saveFeedbackXml.php", {
    method: "POST",
    headers: {
      "Content-Type": "application/xml"
    },
    body: xmlString
  } )
  .then( response => response.text() ) // convert response to JSON
  .then( result => {
    
    const parser = new DOMParser();
    const xml = parser.parseFromString(result, "application/xml");
    document.getElementById("output").textContent = xml.getElementsByTagName("message")[0].outerHTML;
    document.getElementById("content").textContent = prettifyXml( xml.getElementsByTagName("content")[0].outerHTML )
   })
  .catch( error => {
    console.error("Error:", error); // Log any errors to the console
    document.getElementById("output").textContent = "Error: " + error.message; // Display error message in output area
  });

}
