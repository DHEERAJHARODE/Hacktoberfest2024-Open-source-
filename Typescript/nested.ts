export type Address = {
  street: string;
  city: string;
  country:string;
};

export interface Person {
  name: string;
  age: number;
  isStudent: boolean;
  address:Address 
};

let person1: Person = {
  name: 'Hamza Mansoor',
  age: 24,
  isStudent: true,
  address: {
    street: "75 b block ,Model Town",
    city: "Lahore",
    country: "Pakistan"
  }
};
let person2: Person = {
  name: 'terry',
  age: 26,
  isStudent: true,
  address: {
    street: '75 b block ,Model Town',
    city: 'Lahore',
    country: 'Pakistan',
  },
};
console.log(person1, person2);


const displayInfo=(person:Person)=>{
  console.log(`${person.name} lives at ${person.address.street}`);
}

displayInfo(person1);