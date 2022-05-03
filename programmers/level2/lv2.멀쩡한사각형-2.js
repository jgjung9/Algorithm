function solution(w, h) {
    let answer = 0;
    const slope = h / w;
    for (let i = 1; i <= w; i++) {
        answer += Math.ceil(slope * i);
    } 
    answer = w * h - answer;
    return  answer * 2;
}

console.log(solution(8, 12));