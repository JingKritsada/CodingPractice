class Student {
    constructor(studentId, faculty, major) {
        this.studentId = studentId;
        this.faculty = faculty;
        this.major = major;
    }

    displayInfo() {
        console.log(`${this.studentId} ${this.faculty} ${this.major}.`);
    }
}

let student1 = new Student("6731000000", "Engineering");
student1.displayInfo();

//can also create an object without a class definition
let person1 = {}
person1.name = "Captain Awesome";
person1.age = 30;
person1.isStudent = false;

let person2 = {}
person2.name = "Diligent Daisies";
person2.age = 16;
person2.isStudent = true;

let people = [person1, person2];

const peopleJSON = JSON.stringify(people); // JS to JSON
const peopleJS = JSON.parse(peopleJSON); // JSON to JS