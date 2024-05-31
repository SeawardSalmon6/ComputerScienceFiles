import { APP_THEME } from "@/assets/theme";
import { createContext, useMemo, useState } from "react";

export const ThemeContext = createContext({
  theme: APP_THEME,
  currentScheme: "light",
  setCurrentScheme: () => {},
  colors: APP_THEME.light.colors,
});

export function ThemeProvider({ children }) {
  const [theme, setTheme] = useState(APP_THEME);
  const [currentScheme, setCurrentScheme] = useState("light");
  const colors = theme[currentScheme].colors;

  const value = useMemo(
    () => ({
      theme,
      currentScheme,
      setCurrentScheme,
      colors,
    }),
    [colors, theme, currentScheme]
  );

  return (
    <ThemeContext.Provider value={value}>{children}</ThemeContext.Provider>
  );
}
