const alphabet = prompt().charCodeAt(0);

if (alphabet >= 65 && alphabet <= 90) {
  console.log("YES");
} else {
  console.log("NO");
}

// or

const alphabet2 = prompt();

if (alphabet2 === alphabet2.toUpperCase()) {
  console.log("YES");
} else {
  console.log("NO");
}
