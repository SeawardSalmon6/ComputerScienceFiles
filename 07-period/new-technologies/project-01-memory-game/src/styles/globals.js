const getLineHeight = (fontSize, proportion = 1.5) => {
  const lineHeight = fontSize * proportion;
  return lineHeight;
};

export const StyleGuide = {
  colors: {
    black: "#000000",
    dark_blue: "#150050",
    purple: "#3F0071",
    purple_light: "#610094",
    gray_light: "#606770",
    gray: "#444950",
    white: "#f8f8ff",
  },
  typography: {
    body: {
      fontFamily: "Roboto-Regular",
      fontSize: 18,
      lineHeight: getLineHeight(16),
    },
    heading: {
      fontFamily: "Inter-Bold",
      fontSize: 24,
      fontWeight: 700,
      lineHeight: getLineHeight(24, 1.2),
      marginBottom: 20,
    },
  },
};
