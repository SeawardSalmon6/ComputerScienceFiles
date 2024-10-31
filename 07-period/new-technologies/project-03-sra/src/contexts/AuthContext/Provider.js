import {
  loadUsersFromLocalStorage,
  usersReducer,
} from "@/contexts/AuthContext/constants";
import { createContext, useEffect, useMemo, useReducer, useState } from "react";

export const AuthContext = createContext({
  user: null,
  setUser: () => {},
});

export function AuthProvider({ children }) {
  const [users, usersDispatcher] = useReducer(usersReducer, []);
  const [user, setUser] = useState(null);

  const value = useMemo(
    () => ({
      users,
      usersDispatcher,
      user,
      setUser,
    }),
    [user, users]
  );

  useEffect(() => {
    const fetchUsers = async () => {
      const localUsers = await loadUsersFromLocalStorage();
      usersDispatcher({ type: "loadEvents", payload: localUsers });
    };

    fetchUsers();
  }, []);

  return <AuthContext.Provider value={value}>{children}</AuthContext.Provider>;
}
