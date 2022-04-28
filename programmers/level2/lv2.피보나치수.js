function Fibo(n) {
    const fibo = [BigInt(0), BigInt(1)];
    for (let i = 2; i <= n; i++) {
        fibo.push(fibo[i - 2] + fibo[i - 1]);
    }

    return fibo[n];
}

function solution(n) {
    let answer = Number(Fibo(n) % BigInt(1234567));
    return answer;
}

console.log(solution(100000));

// 3	2
// 5	5
