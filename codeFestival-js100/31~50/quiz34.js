const heights = prompt().split(" ");
const sortHeights = Array.from(heights).sort();

if (heights.toString() == sortHeights.toString()) {
  console.log("Yes");
} else {
  console.log("No");
}
