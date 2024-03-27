import { StyleSheet } from "react-native";

export default StyleSheet.create({
  container: {
    maxWidth: 55 * 3 + 8 * 2,
    maxHeight: 300,
    justifyContent: "center",
    alignItems: "flex-end",
    gap: 8,
  },
  row: {
    height: 55,
    flexDirection: "row",
    gap: 8,
  },
  rowButton: {
    width: 55,
    height: 55,
  },
});
