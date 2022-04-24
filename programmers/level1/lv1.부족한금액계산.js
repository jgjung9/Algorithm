function solution(price, money, count) {
  const need = (price * (count + 1) * count) / 2;
  return need > money ? need - money : 0;
}
