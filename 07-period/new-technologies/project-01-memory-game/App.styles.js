import { StyleSheet } from "react-native";
import { StyleGuide } from "./src/styles/globals";

export default StyleSheet.create({
  container: {
    flex: 1,
    alignItems: "center",
    justifyContent: "center",
    paddingVertical: 80,
    backgroundColor: StyleGuide.colors.black,
  },
});
