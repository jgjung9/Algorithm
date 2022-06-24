function solution(orders, course) {
  var answer = [];
  const count = {};

  orders = orders.map((order) => {
    return order.split('').sort().join('');
  });

  function menuCount(order, menu = '', idx = 0) {
    if (menu.length >= 2) {
      count[menu]
        ? count[menu].cnt++
        : (count[menu] = {
            length: menu.length,
            cnt: 1,
          });
    }
    if (menu.length === order.length) return;

    for (let i = idx; i < order.length; i++) {
      menu += order[i];
      menuCount(order, menu, i + 1);
      menu = menu.slice(0, menu.length - 1);
    }
  }

  orders.forEach((order) => {
    menuCount(order);
  });

  course.forEach((v) => {
    let max = 0;
    for (let menu in count) {
      const cnt = count[menu].cnt;
      if (cnt > 1 && count[menu].length === v && max < cnt) {
        max = count[menu].cnt;
      }
    }

    for (let menu in count) {
      if (count[menu].length === v && count[menu].cnt === max) {
        answer.push(menu);
      }
    }
  });

  answer.sort((a, b) => {
    if (a < b) return -1;
    if (a === b) return 0;
    if (a > b) return 1;
  });
  return answer;
}

solution(['ABCDE', 'AB', 'CD', 'ADE', 'XYZ', 'XYZ', 'ACD'], [2, 3, 5]);
