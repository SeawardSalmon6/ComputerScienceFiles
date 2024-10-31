import { APP_COLORS } from "@/assets/theme";
import { StyleSheet } from "react-native";

export default StyleSheet.create({
  container: {
    justifyContent: "center",
    width: 32 * 3,
    paddingVertical: 8,
    borderWidth: 2,
    borderRadius: 24,
    borderColor: APP_COLORS.lightGray,
  },
  slider: {
    width: 32,
    height: 32,
    borderRadius: 100,
  },
});
