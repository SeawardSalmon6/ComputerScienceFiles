import { StyleSheet } from "react-native";
import { StyleGuide } from "../../../styles/globals";

export default StyleSheet.create({
  button: {
    paddingVertical: 12,
    paddingHorizontal: 16,
    borderRadius: 8,
    color: StyleGuide.colors.white,
    backgroundColor: StyleGuide.colors.dark_blue,
    borderWidth: 6,
    borderStyle: "solid",
    borderColor: StyleGuide.colors.purple,
  },
  disabled: {
    borderColor: StyleGuide.colors.gray_light,
    backgroundColor: StyleGuide.colors.gray,
  },
  buttonText: {
    fontFamily: StyleGuide.typography.heading.fontFamily,
    fontSize: 18,
    textAlign: "center",
    textTransform: "uppercase",
  },
});
