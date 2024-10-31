import { AuthContext } from "@/contexts/AuthContext/Provider";
import { useContext } from "react";

export function useAuthContext() {
  return useContext(AuthContext);
}
