import { createContext, useMemo, useState } from "react";
import { getRandomUsers } from "../../constants/users";

export const UsersContext = createContext({
  users: [],
});

export function UsersProvider({ children }) {
  const [users, setUsers] = useState(getRandomUsers(30));

  const value = useMemo(
    () => ({
      users,
      setUsers,
    }),
    [users]
  );

  return (
    <UsersContext.Provider value={value}>{children}</UsersContext.Provider>
  );
}
