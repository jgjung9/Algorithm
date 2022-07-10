/**
 * 문자열 정렬
 * @param {string[]} logs
 * @return {string[]}
 */
var reorderLogFiles = function (logs) {
  logs.sort((a, b) => {
    const l = a.split(' ').slice(1);
    const r = b.split(' ').slice(1);
    if (!isNaN(l[0]) && !isNaN(r[0])) return 0;
    if (!isNaN(l[0]) && isNaN(r[0])) return 1;
    if (isNaN(l[0]) && !isNaN(r[0])) return -1;
    if (l.join() < r.join()) return -1;
    if (l.join() === r.join() && a < b) return -1;
    else return 1;
  });
  return logs;
};
