function getUsersOfLegalAge(users) {
  return users.filter((user) => user.age >= 18).map((user) => user.name);
}

const localUsers = [
  {
    name: 'User 01',
    age: 18,
  },
  {
    name: 'User 02',
    age: 20,
  },
  {
    name: 'User 03',
    age: 15,
  }
];

console.log('All users:', localUsers);
console.log('Of legal age users:', getUsersOfLegalAge(localUsers));

