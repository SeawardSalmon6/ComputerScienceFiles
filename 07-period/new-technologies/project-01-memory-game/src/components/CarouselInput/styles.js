import { StyleSheet } from "react-native";
import { StyleGuide } from "../../styles/globals";

export default StyleSheet.create({
  container: {
    maxHeight: 160,
    maxWidth: 316,
    marginVertical: 20,
    alignItems: "center",
    justifyContent: "center",
    flexDirection: "row",
    flexWrap: "wrap",
    columnGap: 8,
    rowGap: 16,
  },
  input: {
    width: 60,
    height: 60,
    padding: 8,
    borderRadius: 8,
    fontFamily: StyleGuide.typography.body.fontFamily,
    fontSize: 48,
    textAlign: "center",
    borderWidth: 2,
    borderStyle: "solid",
    borderColor: StyleGuide.colors.white,
    color: StyleGuide.colors.white,
    backgroundColor: StyleGuide.colors.purple_light,
  },
  wrapper: {
    position: "relative",
    overflow: "visible",
  },
  indicator: {
    position: "absolute",
    bottom: -10,
    left: 60 / 2 - 18 / 2,
    width: 18,
    height: 20,
    alignItems: "center",
    justifyContent: "center",
    borderRadius: 4,
    borderWidth: 2,
    borderStyle: "solid",
    borderColor: StyleGuide.colors.purple,
    backgroundColor: StyleGuide.colors.white,
  },
});
