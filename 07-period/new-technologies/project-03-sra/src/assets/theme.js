import { StyleSheet } from "react-native";

export const APP_COLORS = {
  darkBlue: "#111740",
  blue: "#1D4666",
  blueLight: "#4C74AC",
  whiteBackground: "#FFFFFF",
  white: "#FFFFFF",
  gray: "#333333",
  lightGray: "#D9D9D9",
  blueishGray: "#767CA0",
};

export const APP_TYPOGRAPHY = StyleSheet.create({
  largeTitle: {
    fontFamily: "Inter-Bold",
    fontSize: 24,
  },
  title: {
    fontFamily: "Inter-SemiBold",
    fontSize: 20,
  },
  subtitle: {
    fontFamily: "Inter-SemiBold",
    fontSize: 18,
  },
  largeText: {
    fontFamily: "Inter-Regular",
    fontSize: 18,
  },
  mediumText: {
    fontFamily: "Inter-Regular",
    fontSize: 15,
  },
  smallText: {
    fontFamily: "Inter-Regular",
    fontSize: 12,
  },
});

export const APP_THEME = {
  light: {
    colors: {
      background: APP_COLORS.whiteBackground,
    },
  },
  dark: {
    colors: {
      background: APP_COLORS.darkBlue,
    },
  },
};
