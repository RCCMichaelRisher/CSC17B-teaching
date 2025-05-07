//function that mimics the behavior of the _GET object in php
function getForm( url ){
  let info = url.split("?");
  let params = info[1].split("&");
  let $_GET = {};
  for (let i = 0; i < params.length; i++) {
    let param = params[i].split("=");
    $_GET[param[0]] = decodeURIComponent(param[1]);
  }

  return $_GET;
}