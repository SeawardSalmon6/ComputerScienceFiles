import { createContext, useMemo, useReducer } from "react";
import { getRandomUsers } from "../../constants/users";
import { usersReducer } from "./constants";

export const UsersContext = createContext({
  users: [],
  usersDispatcher: () => {},
});

export function UsersProvider({ children }) {
  const [users, usersDispatcher] = useReducer(usersReducer, 30, getRandomUsers);

  const value = useMemo(
    () => ({
      users,
      usersDispatcher,
    }),
    [users, usersDispatcher]
  );

  return (
    <UsersContext.Provider value={value}>{children}</UsersContext.Provider>
  );
}
