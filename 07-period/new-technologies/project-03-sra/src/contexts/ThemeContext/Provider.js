import { APP_THEME } from "@/assets/theme";
import { createContext, useMemo, useState } from "react";

export const ThemeContext = createContext({
  currentScheme: "light",
  setCurrentScheme: () => {},
  statusBarStyle: "light",
  setStatusBarStyle: () => {},
  colors: APP_THEME.light.colors,
});

export function ThemeProvider({ children }) {
  const [currentScheme, setCurrentScheme] = useState("light");
  const [statusBarStyle, setStatusBarStyle] = useState("light");
  const colors = APP_THEME[currentScheme].colors;

  const value = useMemo(
    () => ({
      currentScheme,
      setCurrentScheme,
      statusBarStyle,
      setStatusBarStyle,
      colors,
    }),
    [colors, statusBarStyle, currentScheme]
  );

  return (
    <ThemeContext.Provider value={value}>{children}</ThemeContext.Provider>
  );
}
