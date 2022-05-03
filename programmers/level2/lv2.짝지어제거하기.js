function solution(s)
{
    s = s.split('');
    const stack = [];
    
    s.forEach((char, idx) => {
        if (stack.length === 0) {
            stack.push(char);
        } 
        else {
            const temp = stack.pop();
            if (temp !== char) {
                stack.push(temp);
                stack.push(char);
            } 
        }
    });
    
    if (stack.length === 0) return 1;
    return 0;
}

console.log(solution("cdcd"));

// s	result
// baabaa	1
// cdcd	0