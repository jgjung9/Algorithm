// 정규 표현식을 이용한 풀이
function solution(new_id) {
  new_id = new_id
    .toLowerCase()
    .replace(/[^a-z0-9._-]/g, "")
    .replace(/\.+/g, ".")
    .replace(/^\.|\.$/g, "")
    .replace(/^$/g, "a")
    .slice(0, 15)
    .replace(/^\.|\.$/g, "");

  while (new_id.length < 3) {
    new_id += new_id[new_id.length - 1];
  }

  return new_id;
}

solution("=.=");

// 예1	"...!@BaT#*..y.abcdefghijklm"	"bat.y.abcdefghi"
// 예2	"z-+.^."	"z--"
// 예3	"=.="	"aaa"
// 예4	"123_.def"	"123_.def"
// 예5	"abcdefghijklmn.p"	"abcdefghijklmn"
