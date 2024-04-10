import { useContext } from "react";
import { UsersContext } from "./Provider";

export function useUsersContext() {
  return useContext(UsersContext);
}
