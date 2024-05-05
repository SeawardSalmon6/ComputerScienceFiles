import { dark } from "@eva-design/eva";
import { StyleSheet } from "react-native";

export const styles = StyleSheet.create({
  container: {
    flexDirection: "row",
    gap: 12,
    backgroundColor: dark["color-basic-800"],
    paddingBottom: 20,
  },
  input: { flex: 1 },
  button: { height: 40, width: 40 },
});
