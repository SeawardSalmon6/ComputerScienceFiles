import { APP_COLORS, APP_TYPOGRAPHY } from "@/assets/theme";
import { StyleSheet } from "react-native";

export default StyleSheet.create({
  container: {
    paddingTop: 12,
  },
  inputContainer: {
    position: "relative",
    alignItems: "flex-start",
    justifyContent: "center",
    borderRadius: 30,
    borderWidth: 1,
    borderColor: APP_COLORS.lightGray,
  },
  input: {
    width: "100%",
    paddingTop: 12,
    paddingBottom: 14,
    paddingHorizontal: 20,
    fontSize: 16,
    color: APP_COLORS.darkBlue,
  },
  placeholderWrapper: {
    position: "absolute",
    top: 0,
    left: 0,
    paddingVertical: 2,
    paddingHorizontal: 8,
    backgroundColor: APP_COLORS.white,
  },
  placeholder: {
    ...APP_TYPOGRAPHY.mediumText,
    color: APP_COLORS.gray,
  },
  placeholderFloating: {
    ...APP_TYPOGRAPHY.smallText,
  },
  passwordSuffix: {
    ...APP_TYPOGRAPHY.smallText,
    left: undefined,
    right: 0,
    paddingVertical: 12,
    paddingRight: 12,
    paddingLeft: 4,
    fontFamily: "Inter-Medium",
    color: APP_COLORS.darkBlue,
    transform: [{ translateY: 8 }, { translateX: -10 }],
  },
  hasSuffix: {
    paddingRight: 80,
  },
});
