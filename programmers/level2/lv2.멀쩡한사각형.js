function gcd(a, b) {
    if (b === 0) return a;
    return gcd(b, a % b);
}
function solution(w, h) {
    let answer = (w * h) - w - h;
    const width = Math.min(w, h);
    const height = Math.max(w, h);
    answer += gcd(height, width);
    return answer;
}

console.log(solution(8, 12));

// W	H	result
// 8	12	80