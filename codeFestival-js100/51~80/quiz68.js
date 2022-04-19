const timeList = ["12:30", "13:20", "14:13"];
const now = "12:40";

function timeTable(timeList, now) {
  let result = timeList
    .map((item) => {
      let time = new Date();
      let nowTime = new Date();
      nowTime.setHours(now.slice(0, 2), now.slice(3, 5));
      time.setHours(item.slice(0, 2), item.slice(3, 5));
      return time - nowTime;
    })
    .map((item) => {
      if (item < 0) {
        return "지나갔습니다.";
      } else {
        const hour = Math.floor(item / (1000 * 60 * 60));
        const minute = (item % (1000 * 60 * 60)) / (1000 * 60);
        return `${hour}시간 ${minute}분`;
      }
    });
  return result;
}

console.log(timeTable(timeList, now));
