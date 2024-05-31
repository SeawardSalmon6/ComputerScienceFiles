import { ThemeContext } from "@/contexts/ThemeContext/Provider";
import { useContext } from "react";

export function useThemeContext() {
  return useContext(ThemeContext);
}
