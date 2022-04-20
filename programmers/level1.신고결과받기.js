function solution(id_list, report, k) {
    var answer = [];

    const infoID = {};
    for (let x of id_list) {
        const obj = {
            report: [],
            beReported: 0,
            van: false,
        };
        infoID[x] = obj;
    }

    for (let x of report) {
        const list = x.split(" ");
        if (infoID[list[0]].report.includes(list[1])) {
            continue;
        }
        infoID[list[0]].report.push(list[1]);
        infoID[list[1]].beReported++;
        if (infoID[list[1]].beReported > k - 1) {
            infoID[list[1]].van = true;
        }
    }

    for (let x of id_list) {
        let count = 0;
        for (let y of infoID[x].report) {
            if (infoID[y].van) {
                count++;
            }
        }
        answer.push(count);
    }

    console.log(answer);
    return answer;
}

solution(
    ["muzi", "frodo", "apeach", "neo"],
    ["muzi frodo", "apeach frodo", "frodo neo", "muzi neo", "apeach muzi"],
    2
);
