function generateRandomUser(id) {
  const names = [
    "José Santos",
    "Maria Santos",
    "João Silva",
    "Ana Pereira",
    "Carlos Costa",
    "Lucas Souza",
    "Fernanda Alves",
    "Paula Ferreira",
    "Bruno Barbosa",
    "Mariana Lima",
  ];

  const emails = [
    "jose@gmail.com",
    "marias11@gmail.com",
    "j113@gmail.com",
    "ana@gmail.com",
    "carlos@gmail.com",
    "lucas@gmail.com",
    "fernanda@gmail.com",
    "paula@gmail.com",
    "bruno@gmail.com",
    "mariana@gmail.com",
  ];

  const avatars = [
    "https://cdn.pixabay.com/photo/2013/07/13/10/07/man-156584_1280.png",
    "https://cdn.pixabay.com/photo/2017/03/01/22/18/avatar-2109804_1280.png",
    "https://cdn.pixabay.com/photo/2016/08/28/13/12/secondlife-1625903_1280.jpg",
    "https://cdn.pixabay.com/photo/2016/03/31/20/27/avatar-1295773_1280.png",
    "https://cdn.pixabay.com/photo/2016/11/18/23/38/child-1837375_1280.png",
    "https://cdn.pixabay.com/photo/2014/04/03/10/32/user-310807_1280.png",
    "https://cdn.pixabay.com/photo/2017/01/31/21/23/avatar-2027366_1280.png",
    "https://cdn.pixabay.com/photo/2016/11/01/21/11/avatar-1789663_1280.png",
    "https://cdn.pixabay.com/photo/2016/09/01/08/25/smiley-1635464_1280.png",
    "https://cdn.pixabay.com/photo/2016/12/13/16/17/dancer-1904467_1280.png",
  ];

  const randomIndex = Math.floor(Math.random() * names.length);
  const randomAvatarIndex = Math.floor(Math.random() * avatars.length);

  return {
    id,
    name: names[randomIndex],
    email: emails[randomIndex],
    avatarUrl: avatars[randomAvatarIndex],
  };
}

export const getRandomUsers = (length = 0) =>
  Array.from({ length }, (_, i) => generateRandomUser(i + 1));
