import { APP_COLORS, APP_TYPOGRAPHY } from "@/assets/theme";
import { StyleSheet } from "react-native";

const CODE_INPUT_WIDTH_HEIGHT = 48;
const CODE_INPUT_CONTAINER_GAP = 14;

export default StyleSheet.create({
  container: {
    paddingTop: 12,
  },
  codeInputContainer: {
    maxWidth: CODE_INPUT_WIDTH_HEIGHT * 5 + CODE_INPUT_CONTAINER_GAP * 4,
    flexDirection: "row",
    alignItems: "center",
    justifyContent: "center",
    flexWrap: "wrap",
    gap: 14,
  },
  inputContainer: {
    position: "relative",
    alignItems: "flex-start",
    justifyContent: "center",
    borderRadius: 30,
    borderWidth: 1,
    borderColor: APP_COLORS.lightGray,
  },
  error: {
    borderColor: "red",
  },
  codeInputWrapper: {
    flexDirection: "row",
    alignItems: "center",
    justifyContent: "center",
    borderRadius: 100,
  },
  input: {
    ...APP_TYPOGRAPHY.mediumText,
    width: "100%",
    paddingTop: 12,
    paddingBottom: 14,
    paddingHorizontal: 20,
    fontSize: 16,
    color: APP_COLORS.darkBlue,
  },
  codeInput: {
    width: CODE_INPUT_WIDTH_HEIGHT,
    height: CODE_INPUT_WIDTH_HEIGHT,
    padding: 0,
    textAlign: "center",
    textAlignVertical: "center",
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
  errorMessage: {
    ...APP_TYPOGRAPHY.mediumText,
    color: "red",
    marginTop: 4,
  },
});
